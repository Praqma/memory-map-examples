# memory-map-examples

Repository for small c/c++ projects that can produce memory maps file from the compile and linking process  to analyse memory consumption by using for example the [Jenkins Memory Map Plugin](https://wiki.jenkins-ci.org/display/JENKINS/Memory+Map+Plugin).


The idea with these examples are to use them as test base for the [Jenkins Memory Map Plugin](https://wiki.jenkins-ci.org/display/JENKINS/Memory+Map+Plugin), gathering examples on different linker command files, compilers and the resulting memory map files when building them.

The users of the plugin can contribute (see XXXXXXXXXXXXX FIXME ref to contribute section below XXXXXXXXXXXX)  with examples to this repository, and they are automatically used in  the test suite in the Memory Map Plugin (see XXXXXXXXX insert reference here to memory-map-plugin repository readme - section about testing FIXME XXXXXXXXXXXXXXXXXXXXXX)

The examples could also serve as test base scripts and other solutions that mimics the behavior of the Memory Map Plugin if not using [Jenkins CI](http://jenkins-ci.org/).

## Example requirements

Each example is contained on a branch in this repository, and have associated files in the `examples`-directory.

You must prepare a set of commits that changes the an example source code project, commit by commit, to show how a memory map changes for each commit. We will automatically build each commit and analyse the memory map output file.
Associated with the series of commit on the example branch, you must supply some files in the `example`-directory, like expected memory map output results, a graph configuration for the Memory Map Plugin you find relevant.

Branch and directories:

* create a branch from latest `master`, where your new branch name must contain compiler and version number in the name (e.g. `arm-none-eabi-gcc_4.8.4_hello_world`)
* create a matching directory in examples (e.g. `examples/arm-none-eabi-gcc_4.8.4_hello_world`)

Example commits:

* a series of commits that changes the memory usage must be added to the branch, in consecutive order and all buildable
* the first, respectively the last, commit in the serie must be tagged `first_%BRANCHNAME` and `last_%BRANCHNAME` (e.g. `first_arm-none-eabi-gcc_4.8.4_hello_world` and `last_arm-none-eabi-gcc_4.8.4_hello_world`)

Build information:

* an automated prepared build environment, preferable using docker, must be available to use for building so we know how to build it
* if you supply your own docker file for building a docker image name it `Dockerfile` and place it in the relevant example directory (e.g. `examples/arm-none-eabi-gcc_4.8.4_hello_world/Dockerfile`)
* there must be an elaborate readme explaing how to use the example, it must be called `README.md` and placed on the branch and completely replace the `README.md` from the `master`-branch
* on the branch, for every commit, there must be a `run.sh` script file that will the source code checked out in the repository

Associated example files:

In the examples directory, the following files need to be available:

* Optional: `Dockerfile` to build an image
* `expectedResults.json` that explains the expected memory map output file result (see one of the other examples)
* `graphConfiguration.json` explaining how to configure the Memory Map Plugin graphs (see one of the other examples)
* Optional: If you run the examples manually you can also add the generated series of memory map files to the example directory for reference. See for example `examples/arm-none-eabi-gcc_4.8.4_hello_world/commit*_blink.map`.



**We can support and help with everything else than the source code changes and how to build it... send us an mail or just contribute what-ever you have through a pull request**



## Get your example tested

If you find out that the Memory Map Plugin fails to analyse your exact combination of linker/command setup, and the resulting memory map please contribute with data to our tests. Then you also easily can raise a [Jenkins JiRA issue](https://issues.jenkins-ci.org/issues/?jql=project%20%3D%20JENKINS%20AND%20status%20in%20%28Open%2C%20%22In%20Progress%22%2C%20Reopened%29%20AND%20component%20%3D%20%27memory-map-plugin%27) and point to your contributing example that fails.

You have two choices:

* Supply a linker comand file, and example memory map file generated with that setup as a one-off test. In this case you can make a pull request adding them to the integration tests of the [Memory Map Plugin](https://wiki.jenkins-ci.org/display/JENKINS/Memory+Map+Plugin), or simple attache them to the JIRA issue you create.
* create an example branch in this repository as explained


## Updating examples

If an example requires to be updated, you must create a new branch for the updated example.

E.g. branch `arm-none-eabi-gcc_4.8.4_hello_world` becomes `arm-none-eabi-gcc_4.8.4_hello_world_update1`.

Delete the old branch, and add a changelog section to the branch readme. Also remember to rename the example directory to match.

Git cherry-pick will help you pick out commits for the new branch, and even modify them before committing them using the `--no-commit` paramter.


## Merging branches

Do not try to merge branches, they are used as isolated work spaces. They are not supposed to be merged with master or each other.

## Contributions

Please contribute by pull request.


## Support and issue

Send a mail to support@praqma.net