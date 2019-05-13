#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

int get_term_char() {
  struct termios previous_term_conf, new_term_conf;

  tcgetattr(STDIN_FILENO, &previous_term_conf);
  // Create copy of terminal configuration
  new_term_conf = previous_term_conf;

  // Temporary change terminal configuration to not display entered signs
  new_term_conf.c_lflag &= ~(ICANON | ECHO);
  tcsetattr(STDIN_FILENO, TCSANOW, &new_term_conf);

  // Get char and restore previous configuration
  int ch = getchar();
  tcsetattr(STDIN_FILENO, TCSANOW, &previous_term_conf);
  return ch;
}

int main(void) {
  char *morse_code[] = {".- ",   "-... ", "-.-. ", "-.. ",  ". ",    "..-. ",
                        "--. ",  ".... ", ".. ",   ".--- ", "-.- ",  ".-.. ",
                        "-- ",   "-. ",   "--- ",  ".--. ", "--.- ", ".-. ",
                        "... ",  "- ",    "..- ",  "...- ", ".-- ",  "-..- ",
                        "-.-- ", "--.. "};
  char bufor[6] = "";
  char sign;

  while (1) {
    // TODO: Catch exception like number of special char
    sign = get_term_char();

    // If user entered new line sign, break main loop
    if (sign == '\n')
      break;

    strcpy(bufor, morse_code[sign - 'a']);
    write(1, bufor, 6);
  }

  return 0;
}
