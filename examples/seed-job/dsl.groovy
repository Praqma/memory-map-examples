BRANCH="master"
BASE_NAME="memory-map-examples"
REPO="https://github.com/Praqma/memory-map-examples.git"

import groovy.json.JsonSlurper

def jsonSlurper = new JsonSlurper()
def config = jsonSlurper.parseText(readFileFromWorkspace('config.json'))

freeStyleJob("${BASE_NAME}_demo-branch_GEN") {
    description('FIXME ')
    logRotator(-1, 500, -1, -1)
    scm {
        git {
            remote {
                url("${REPO}")
            }
            branch("${BRANCH}")
        }
    }
    steps {
        shell('''
#!/bin/bash
./run.sh
''')
    }
    configure { project ->
        project / publishers << 'net.praqma.jenkins.memorymap.MemoryMapRecorder' {
            wordSize 			config.wordSize
            showBytesOnGraph 	config.showBytesOnGraph
            scale 				config.scale
            chosenParsers		{
                config.chosenParsers.each{parserType, parserList ->
                    def parserConfig = config.chosenParsers[parserType];
                    for (p = 0; p < parserList.size() ; p++) {
                        "$parserType" {
                            parserUniqueName    parserConfig['parserUniqueName'][p]
                            parserTitle         parserConfig['parserTitle'][p]
                            mapFile             parserConfig['mapFile'][p]
                            configurationFile   parserConfig['configurationFile'][p]
                            graphConfiguration {
                                def graphConfig = parserConfig['graphConfiguration'][p].values().toList()[0]
                                for (g = 0; g < graphConfig.size() ; g++) {
                                    'net.praqma.jenkins.memorymap.graph.MemoryMapGraphConfiguration' {
                                        graphCaption	graphConfig[g]['graphCaption']
                                        graphDataList	graphConfig[g]['graphDataList']
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
