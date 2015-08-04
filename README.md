# memory-map-examples

Repository for small c/c++ projects that can produce memory maps file from the compile and linking process  to analyse memory consumption by using for example the [Jenkins Memory Map Plugin](https://wiki.jenkins-ci.org/display/JENKINS/Memory+Map+Plugin).


The idea with these examples are to use them as test base for the [Jenkins Memory Map Plugin](https://wiki.jenkins-ci.org/display/JENKINS/Memory+Map+Plugin), gathering examples on different linker command files, compilers and the resulting memory map files when building them.

The users of the plugin can contribute (see XXXXXXXXXXXXX FIXME ref to contribute section below XXXXXXXXXXXX)  with examples to this repository, and they are automatically used in  the test suite in the Memory Map Plugin (see XXXXXXXXX insert reference here to memory-map-plugin repository readme - section about testing FIXME XXXXXXXXXXXXXXXXXXXXXX)

The examples could also serve as test base scripts and other solutions that mimics the behavior of the Memory Map Plugin if not using [Jenkins CI](http://jenkins-ci.org/).

## Example requirements

Each example is contained on a branch in this repository and must meet few requirements to make us able to automate testing:

* create example from latest `master`
* branch name must contain compiler and version number in the name (e.g. `arm-none-eabi-gcc_4.8.4_hello_world`)
* an automated prepared build environment, preferable using docker, must be available to use for building
* there must be an elaborate readme explaing how to use the example
* a series of commits that changes the memory usage must be added to the branch, in consecutive order and all buildable
* the first, respectively the last, commit in the serie must be tagged `first_%BRANCHNAME` and `last_%BRANCHNAME` (e.g. `first_arm-none-eabi-gcc_4.8.4_hello_world` and `last_arm-none-eabi-gcc_4.8.4_hello_world`)
* if a docker file is supplied for building a docker image it must be named after the branch as `%BRANCHNAME.dockerfile` (e.g. `arm-none-eabi-gcc_4.8.4_hello_world.dockerfile`)


## Merging to master

Branches are not supposed to be merged to master, nor updating from master. Branches are just used to isolate examples.

## Updating examples

If an example requires to be updated, you must create a new branch for the updated example.

E.g. branch `arm-none-eabi-gcc_4.8.4_hello_world` becomes `arm-none-eabi-gcc_4.8.4_hello_world_update1`.

Delete the old branch, and add a changelog section to the branch readme.



## Contributions

Please contribute by pull request.