fifo: srvfifo.c cntfifo.c
	gcc srvfifo.c -o srvfifo
	gcc cntfifo.c -o cntfifo

system_v: srvsv.c cntsv.c
	gcc srvsv.c -o srvsv
	gcc cntsv.c -o cntsv

posix: srvpsx.c cntpsx.c
	gcc srvpsx.c -o srvpsx -lrt
	gcc cntpsx.c -o cntpsx -lrt

all: fifo system_v posix

clean:
	rm -f *~ *.o srvfifo cntfifo srvsv cntsv srvpsx cntpsx
	find . -name 'fifo[0-9]*' -exec rm -rf {} \;
