# Fillit

Fillit is a project which involves discovering and getting acquainted with a recurrent problem in programming:
the search of an optimal solution among a very large number of possibilities in a reasonable amount of time. 
In this project, we had to arrange Tetriminos among them and determine the smallest square that can fit all of them.
Also, it was very important that we had to handle wrong inputs (eg. invalid file or tetris shapes), memory leaks and replace
each tetris piece to letters according to its order in the file for better visualization.

This project was the first time after the Piscine selection where we had to form a group of two students to work together,
simulating a work environment. Big shout out to my parter and good friend @Bkonjuha.

# How to use it?

> git clone "my repo URL" "your folder path"

This time you don't need to go inside my libft folder to compile it. Now you can compile it through a Makefile in the root of my Repo
> make

This will compile my library with useful C functions and my fillit files, creating an executable called **fillit**

In order to run the executable, type:
> ./fillit "file name you would like it to solve with tetris pieces"

![Image of Subject](https://github.com/MuSuareZ/Fillit/blob/master/img/subject.png)

***Remember that each piece should be separated by one space (VIM editor or NANO by default already inputs a space in the end of the file)!***

***PS: You should always ignore the quotation marks, they are just comments of what you should input***

# Debug

***If you have a MacOS/Linux, follow step 1.a and then step 2. If you have a Windows system, follow step 1.b, step 1.a and then step 2.***

***Step 1.a***
If you are having some issues and would like to see what's happening and you are brave enough to modify some code lines,
I recommend you to open solve.c with your favorite text editor (VIM please :D ), find the function:
> int   solve(t_data *tetris, t_map *mappi)

There you will find 4 special lines commented out by //
> (line 98) // system("clear");

> (line 99) // print_map(mappi->map);

> (line 100) // usleep(10000);

> (line 118) // system("clear");

Please remove the // so it will look like this:
> system("clear");

> print_map(mappi->map);

> usleep(10000);

> system("clear");

***Step 1.b***
On the lines *// system("clear");* , clear is not a command recognized by Windows, but cls is and it does the same thing that we need.
With that in mind, you would need to change all the "clear" commands into "cls" like this:

> (line 98) // system("clear");

> (line 118) // system("clear");

to

> (line 98) // system("cls");

> (line 118) // system("cls");

Now just move back to ***Step 1.a*** and you are good to go!

***Step 2***

Remember to re-compile our program since we modify its source files:
> make re

Now run your test file with fillit executable as explained above and you will be able to visualize the test solving itself
in each iteration of the loop! Awesome, isn't it?

What's happening there is that we are clearing our screen from previous prints, printing the actual map situation and telling the program to sleep for 0.015 seconds
in order to make sure the user can see what changed and then repeating these steps until everything is done.

# What to improve?

There is always room for improvements in terms of performance and readability. In the future I might also implement the
error messages to make it more descriptive about what is wrong, so the user will know what to fix.
