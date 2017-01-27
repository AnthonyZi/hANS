MAKE = make
CC = gcc
CXX = g++

##################
CFLAGS = -Wall -std=c++14 -O3 #-g -O3
CXXFLAGS = $(CFLAGS)
LDFLAGS =

LIBS = $(ADDITIONALCFLAGS) #-lgtkmm-3.0 -latkmm-1.6 -lgdkmm-3.0 -lgiomm-2.4 -lpangomm-1.4 -lglibmm-2.4 -lgtk-3 -lgdk-3 -lpangocairo-1.0 -lpango-1.0 -latk-1.0 -lcairo-gobject -lgio-2.0 -lcairomm-1.0 -lcairo -lsigc-2.0 -lgdk_pixbuf-2.0 -lgobject-2.0 -lglib-2.0 

ADDITIONALCFLAGS = #-pthread -I/usr/include/gtkmm-3.0 -I/usr/lib/i386-linux-gnu/gtkmm-3.0/include -I/usr/include/atkmm-1.6 -I/usr/include/gtk-3.0/unix-print -I/usr/include/gdkmm-3.0 -I/usr/lib/i386-linux-gnu/gdkmm-3.0/include -I/usr/include/giomm-2.4 -I/usr/lib/i386-linux-gnu/giomm-2.4/include -I/usr/include/pangomm-1.4 -I/usr/lib/i386-linux-gnu/pangomm-1.4/include -I/usr/include/glibmm-2.4 -I/usr/lib/i386-linux-gnu/glibmm-2.4/include -I/usr/include/gtk-3.0 -I/usr/include/at-spi2-atk/2.0 -I/usr/include/at-spi-2.0 -I/usr/include/dbus-1.0 -I/usr/lib/i386-linux-gnu/dbus-1.0/include -I/usr/include/gtk-3.0 -I/usr/include/gio-unix-2.0/ -I/usr/include/cairo -I/usr/include/pango-1.0 -I/usr/include/harfbuzz -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng12 -I/usr/include/sigc++-2.0 -I/usr/lib/i386-linux-gnu/sigc++-2.0/include -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/libpng12 -I/usr/include/glib-2.0 -I/usr/lib/i386-linux-gnu/glib-2.0/include -I/usr/include/cairomm-1.0 -I/usr/lib/cairomm-1.0/include 

NAME = aitest

CSOURCE =
CPPSOURCE = ai.cpp hans.cpp hanslayer.cpp hanslayer_dense.cpp transferer.cpp costs.cpp

#################

OBJS += $(patsubst %.cpp, %.o, $(filter %.cpp, $(CPPSOURCE)))
OBJS += $(patsubst $.c, %.o, $(filter %.c, $(CSOURCE)))

%.o : %.c %.h
	$(CC) -c $(CFLAGS) -o $@ $< $(ADDITIONALCFLAGS)

%.o : %.cpp %.h
	$(CXX) -c $(CXXFLAGS) -o $@ $< $(ADDITIONALCFLAGS)

default : $(NAME)
	$(MAKE) $(NAME)

e :
	clear
	$(MAKE) $(NAME)
	clear
	./$(NAME)
debug :
	clear
	$(CFLAGS) += -g
	$(MAKE) $(NAME)
	clear
	gdb ./$(NAME)


all :
	$(MAKE) $(NAME)	

$(NAME) : $(OBJS)
	$(CXX) $(CFLAGS) -o $(NAME) $(OBJS) $(LDFLAGS)

clean :
	rm -rf *.o

veryclean : clean
	rm -rf $(NAME)

depend :
	$(CXX) -MM $(CFLAGS) $(CSOURCE) $(CPPSOURCE) > Makefile.dep

-include Makefile.dep

.PHONY: all clean default depend veryclean
