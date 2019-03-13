#include <grp.h>
#include <libgen.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>

/* --------------------------------------------------------------------------------
 */

static void print_type(struct stat *lsb);
static void print_ino(const struct stat *sb);
static void print_perms(const struct stat *sb, char *path);
static void print_linkc(const struct stat *sb);
static void print_owner(const struct stat *sb);
static void print_size(const struct stat *sb);
static void print_laststch(const struct stat *sb);
static void print_lastacc(const struct stat *sb);
static void print_lastmod(const struct stat *sb);
static void print_name(const struct stat *lsb, char *name);
char *getRelatedDateString(long long sec);
int getRelatedDateInt(long long sec);

/* --------------------------------------------------------------------------------
 */

int main(int argc, char *argv[]) {
  struct stat sb;
  struct stat lsb;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  if (stat(argv[1], &sb) == -1) {
    perror("stat");
    exit(EXIT_SUCCESS);
  }

  if (lstat(argv[1], &lsb) == -1) {
    perror("lstat");
    exit(EXIT_SUCCESS);
  }

  print_type(&lsb);
  print_name(&lsb, argv[1]);
  print_ino(&sb);
  print_perms(&sb, argv[1]);
  print_linkc(&sb);
  print_owner(&sb);
  print_size(&sb);
  print_laststch(&sb);
  print_lastacc(&sb);
  print_lastmod(&sb);

  exit(EXIT_SUCCESS);
}

/* --------------------------------------------------------------------------------
 */

static void print_type(struct stat *lsb) {
  printf("File type:                ");
  switch (lsb->st_mode & S_IFMT) {
  case S_IFBLK:
    printf("block device\n");
    break;
  case S_IFCHR:
    printf("character device\n");
    break;
  case S_IFSOCK:
    printf("socket\n");
    break;
  case S_IFLNK:
    printf("symbolic link\n");
    break;
  case S_IFREG:
    printf("regular file\n");
    break;
  case S_IFDIR:
    printf("directory\n");
    break;
  case S_IFIFO:
    printf("FIFO queue\n");
    break;
  default:
    printf("unknown?\n");
    break;
  }
}

/* --------------------------------------------------------------------------------
 */

static void print_ino(const struct stat *sb) {
  printf("I-node number:            %ld\n", (long)sb->st_ino);
}

/* --------------------------------------------------------------------------------
 */

static void print_perms(const struct stat *sb, char *path) {
  int statchmod = sb->st_mode & (S_IRWXU | S_IRWXG | S_IRWXO);
  printf("Mode:                     %o\n", statchmod);

  char *read_access = access(path, R_OK) ? "yes" : "no";
  char *write_access = access(path, W_OK) ? "yes" : "no";

  char *execute_access = access(path, X_OK) ? "yes" : "no";
  printf("Your permisions:          read: %s, write: %s, execute: %s.\n",
         read_access, write_access, execute_access);
}

/* --------------------------------------------------------------------------------
 */

static void print_linkc(const struct stat *sb) {
  printf("Link count:               %ld\n", (long)sb->st_nlink);
}

/* --------------------------------------------------------------------------------
 */

static void print_owner(const struct stat *sb) {
  struct passwd *pw = getpwuid(sb->st_uid);
  struct group *gr = getgrgid(sb->st_gid);

  printf("Ownership:                %s(%ld)   %s(%ld)\n", pw->pw_name,
         (long)sb->st_uid, gr->gr_name, (long)sb->st_gid);
}

/* --------------------------------------------------------------------------------
 */

static void print_size(const struct stat *sb) {
  static const char *SIZES[] = {"B", "kB", "MB", "GB"};
  size_t div = 0;
  size_t rem = 0;
  size_t size = sb->st_size;

  while (size >= 1024 && div < (sizeof SIZES / sizeof *SIZES)) {
    rem = (size % 1024);
    div++;
    size /= 1024;
  }

  printf("Preferred I/O block size: %ld bytes\n", (long)sb->st_blksize);
  printf("File size:                %.1f%s\n",
         (float)size + (float)rem / 1024.0, SIZES[div]);
  printf("Blocks allocated:         %lld\n", (long long)sb->st_blocks);
}

/* --------------------------------------------------------------------------------
 */

static void print_laststch(const struct stat *sb) {
  time_t now;
  time(&now);
  long long seconds;
  seconds = difftime(now, sb->st_ctime);
  char *related_date_string = getRelatedDateString(seconds);
  int related_date_int = getRelatedDateInt(seconds);
  printf("Last status change:       %s", ctime(&sb->st_ctime));
  printf("Last status change:       %d %s\n", related_date_int,
         related_date_string);
}

/* --------------------------------------------------------------------------------
 */

static void print_lastacc(const struct stat *sb) {
  time_t now;
  time(&now);
  long long seconds;
  seconds = difftime(now, sb->st_atime);
  char *related_date_string = getRelatedDateString(seconds);
  int related_date_int = getRelatedDateInt(seconds);
  printf("Last file access:         %s", ctime(&sb->st_atime));
  printf("Last file access:         %d %s\n", related_date_int,
         related_date_string);
}

/* --------------------------------------------------------------------------------
 */

static void print_lastmod(const struct stat *sb) {
  time_t now;
  time(&now);
  long long seconds;
  seconds = difftime(now, sb->st_mtime);
  char *related_date_string = getRelatedDateString(seconds);
  int related_date_int = getRelatedDateInt(seconds);
  printf("Last file modification:   %s", ctime(&sb->st_mtime));
  printf("Last file modification:   %d %s\n", related_date_int,
         related_date_string);
}

/* --------------------------------------------------------------------------------
 */

char *getRelatedDateString(long long sec) {
  char *result;
  if (sec < 60) {
    result = "second(s) ago";
  } else if (sec >= 60 && sec < 3600) {
    result = "minute(s) ago";
  } else if (sec >= 3600 && sec < 86400) {
    result = "hour(s) ago";
  } else {
    result = "day(s) ago";
  }
  return result;
}

/* --------------------------------------------------------------------------------
 */

int getRelatedDateInt(long long sec) {
  int result = 0;
  if (sec >= 60 && sec < 3600) {
    result = sec / 60;
  } else if (sec >= 3600 && sec < 86400) {
    result = sec / 3600;
  } else {
    result = sec;
  }
  return result;
}

/* --------------------------------------------------------------------------------
 */

static void print_name(const struct stat *lsb, char *name) {
  char *bname = basename(name);
  char *lname = (char *)malloc(128 * sizeof(char));

  if (S_ISLNK(lsb->st_mode)) {
    int count = readlink(name, lname, sizeof(lname));
    if (count >= 0) {
      lname[count] = '\0';
      printf("Name of the file:         %s -> %s\n", name, lname);
    } else {
      printf("Name of the file:         Can not read link from file %s\n",
             bname);
    }
  } else
    printf("Name of the file:         %s\n", bname);
}

/* --------------------------------------------------------------------------------
 */
