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

## Get your example tested

If you find out that the Memory Map Plugin fails to analyse your exact combination of linker/command setup, and the resulting memory map please contribute with data to our tests. Then you also easily can raise a [Jenkins JiRA issue](https://issues.jenkins-ci.org/issues/?jql=project%20%3D%20JENKINS%20AND%20status%20in%20%28Open%2C%20%22In%20Progress%22%2C%20Reopened%29%20AND%20component%20%3D%20%27memory-map-plugin%27) and point to your contributing example that fails.

You have two choices:

* Supply a linker comand file, and example memory map file generated with that setup as a one-off test. In this case you can make a pull request adding them to the integration tests of the [Memory Map Plugin](https://wiki.jenkins-ci.org/display/JENKINS/Memory+Map+Plugin), or simple attache them to the JIRA issue you create.
* create an example branch in this repository as explained


## Creating a new examples

Here is the work flow we find the easiest to use:

* branch of master to `dev/myexample`
* write a new readme, use another example branch as example
* add/remove needed source code files, makefiles, required scripts etc. Analyse and generate memory map file, manually extract the result and write the expected results json file for this first commit. You can even save the resulting memory map file, maybe adding comments in it to a new file name, eg. mymapp-1.map for the map file the first commit will create.
* commit this first example, including the JSON file
* then start doing small code changes, committing them one by one, so they form an interesting and valid use case for memory maps. Make sure to add to the expected result JSON file for every commit

Save the final expected result JSON file, and the final readme file (if you have changed on the way). We need them in a moment.

When you have a series of commit that makes out your example, you need to prepare the real example branch:

* branch of master again (same commmit) but to `myexample`
* git cherry-pick the first commit from `dev/myexample` with `git cherry-pick --no-commit SHA`. Before committing, add the correct final readme and the final expected result JSON file. Commit with nice commit message.
* repeat the cherry-pick process for every commit on the dev branch
* remember to add the _first_ and _last_ tag
* finally add the graphConfiguration.json file explaining how the Memory Map Plugin for Jenkins jobs should be configured.


If you need to rework and modify an existing example, follow the cherry-pick process but give the example branch a new name as explained just below.


## Updating examples

If an example requires to be updated, you must create a new branch for the updated example.

E.g. branch `arm-none-eabi-gcc_4.8.4_hello_world` becomes `arm-none-eabi-gcc_4.8.4_hello_world_update1`.

Delete the old branch, and add a changelog section to the branch readme.

## Merging branches

Do not try to merge branches, they are used as isolated work spaces. They are not supposed to be merged with master or each other.



## Contributions

Please contribute by pull request.
