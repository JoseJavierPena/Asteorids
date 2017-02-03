# Applied's Programming Course
## Today's Agenda

Classes are an expanded concept of data structures: like data structures, they can contain data members, but they can also contain functions as members.

    class Rectangle {
      int width, height;
      public:
        void set_values (int,int);
        int area (void);
    };

An object is an instantiation of a class. In terms of variables, a class would be the type, and an object would be the variable.

    Rectangle rect;

You can read more about classess and their syntax [here](http://www.cplusplus.com/doc/tutorial/classes/) and [here](https://www.tutorialspoint.com/cplusplus/cpp_classes_objects.htm). This information will come handy once we move forward and refactor the assigment we will be down today.

## Assignment
Modify your asteroids project to do the following:
* Create a new directory. Call it models
  * Download the three text files attached to this gist: *falcon.points*, *enterprise.points* & *ship.points*. Place them within the **models** directory.
* Modify the main class, add code to list the contents of the **models** directory. It's path should be relative to the root of your code. Getting the code is not enough, you need to add code to handle the different distribution scenarios that might arise when performing a solution build. In order to get this to work, you need to perform a post build task in visual studio that moves the models directory and it's content to the build path were your binaries are being compiled to.
  * [Here's](https://msdn.microsoft.com/en-us/library/windows/desktop/aa365200(v=vs.85).aspx) a good starting point for the file listing.
  * [How to: Specify Custom Actions That Run Pre-build or Post-build](https://msdn.microsoft.com/en-us/library/aa833213(v=vs.100).aspx)
  * [XCOPY](https://support.microsoft.com/en-us/help/240268/copy,-xcopy,-and-move-overwrite-functionality-changes-in-windows)
  * After all of this is in place, your code should list the contents of the **models** directory for Debug & Release builds.
* Modify the listing code to read the contents of each file:
  * Each element is a single-precision floating point and it should be allocated as is.
  * Each element is separated by commas.
  * You should print out to the console each line in the following format %f - %f.