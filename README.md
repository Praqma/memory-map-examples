# arm-none-eabi-gcc 4.8.4 hello world

Hello World ARM example from the the book [Programming Embedded Systems, With C and
GNU Development Tools, 2nd Edition](http://www.oreilly.com/catalog/embsys2).

It uses GNU Arm croos-compiler version 4.8.4 and an example from the book above.

## Build environment

The docker file uses a debian based GCC docker base image and adds the GNU Arm GCC cross-compiler from launchpad.

## Using docker and building the example

Check the `run.sh` file or read the following to build manually.

First you need to build the docker image from the supplied docker file. We recommend using the command below. 

* uses git to get the current branch name
* assumes the docker file conforms the usual standard name `Dockerfile`
* gives the locally build image the name $BRANCHNAME and tag `latest`

```
	docker build --rm -f Dockerfile -t `git symbolic-ref HEAD | sed -e 's,.*/\(.*\),\1,'`:latest .
```
Now you should be able to build the example using the docker container.

* assumes that current directory contains this readme file you are reading (... that is, a clone of the _memory-map-eamples_ repository on the relevant branch)
* assumes you have build the image above

```
	docker run -v `pwd`:/data `git symbolic-ref HEAD | sed -e 's,.*/\(.*\),\1,'`:latest make clean all
```
It is a good idea to save the name branch name and the name of a docker image just build:

```
	export BN=`git symbolic-ref HEAD | sed -e 's,.*/\(.*\),\1,'`
	export DKRIMG=$BN:latest
```

## The hello world example

This branch have several commits, between the `first_%BRANCHNAME` and the `last_%BRANCHNAME` tags, that changes the hello world example source code showing changes in the produced memory map files.

For example adding an integer array that consumes more memory in the `.text` section.

## Producing different map files

You can see examples of source code changes, and the resulting memory map files, by checking out different version and compile the example:

_Export the branch name and the docker image name we are using as we are about to checkout branches som git symbolic-ref returns another name_:

```
	export BN=`git symbolic-ref HEAD | sed -e 's,.*/\(.*\),\1,'`
	export DKRIMG=$BN:latest
```
_checkout the SHA in the workflow between the tags to get the basic example source code_:

```
	git checkout `git log --format=format:%H --reverse first_$BN^1..last_$BN | sed -n 1p`
```
_compile:_ (not the git command finding your image is different from above examples!)

```
	docker run -v `pwd`:/data $DKRIMG make clean all
```
_save your map file for later comparison ...our use the [Jenkins Memory Map Plugin](https://wiki.jenkins-ci.org/display/JENKINS/Memory+Map+Plugin) to analyse it ;-)_

	cp -v blink.map blink-`git describe --tags`.map

_try same work flow again, but use the second and third commit that introduces change memory usage_:
```
	git checkout `git log --format=format:%H --reverse first_$BN^1..last_$BN | sed -n 2p`
	docker run -v `pwd`:/data $DKRIMG make clean all
	cp -v blink.map blink-`git describe --tags`.map
	git checkout `git log --format=format:%H --reverse first_$BN^1..last_$BN | sed -n 3p`
	docker run -v `pwd`:/data $DKRIMG make clean all
	cp -v blink.map blink-`git describe --tags`.map
```
There is now three blink memory map files you can analyse and compare to the code changes :-)

As you probably already figured out, the `sed -n 3p` it the third commit from the `first` tag. You can list and count the number of commit you can try to build with these commands:

_List SHAs between `first` and `last` tags_:
	
	git log --format=format:%H --reverse first_$BN^1..last_$BN

_count them_:

	git log --format=format:%H --reverse first_$BN^1..last_$BN | wc -w
	


## References

The example is also referenced and explained in more details on [http://www.bogotobogo.com/cplusplus/embeddedSystemsProgramming_gnu_toolchain_ARM_cross_compiler.php](http://www.bogotobogo.com/cplusplus/embeddedSystemsProgramming_gnu_toolchain_ARM_cross_compiler.php)

A good reference explaining about the memory sections: [http://mcuoneclipse.com/2013/04/14/text-data-and-bss-code-and-data-size-explained](http://mcuoneclipse.com/2013/04/14/text-data-and-bss-code-and-data-size-explained)


## Changelog

_These are the branches that have existed for this example over time (topmost is the current):_

__arm-none-eabi-gcc_4.8.4_hello_world_update1__

  * Moved associated files like expected results etc. to the master branch example directory, for easier maintenance.

__arm-none-eabi-gcc_4.8.4_hello_world__

  * The initial example created