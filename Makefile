##
# bifid
#
# A bifid implementation in C
# By: Andy Sparks and [insert partner name here]
#
# @file
# @version 0.1

binary = bifid
objects = main.o

$(binary) : $(objects)
	cc $(objects) -o $(binary)

Phony : clean run

run : $(binary)
	./$(binary)

clean : $(binary) $(objects)
	rm $(binary) $(objects)

# end
