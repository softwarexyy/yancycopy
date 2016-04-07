##############	Make file for readfile by yancy	#############

yancycopy:main.c
	gcc main.c -o yancycopy
clean:
	rm yancycopy

#	install the yancycopy software
install:yancycopy
	sudo cp ./yancycopy /bin

#	uninstall the software
uninstall:/bin/yancycopy	./yancycopy
	sudo rm -rf /bin/yancycopy ./yancycopy
