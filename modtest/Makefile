obj-m	:= modtest.o
ROOTDIR	:= /lib/modules/$(shell uname -r)/build 
PWD	:= $(shell pwd)
default:
	$(MAKE) -C $(ROOTDIR) M=$(PWD) 
clean:
	$(MAKE) -C $(ROOTDIR) M=$(PWD) clean
