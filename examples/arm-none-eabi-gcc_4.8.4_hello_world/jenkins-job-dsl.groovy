freeStyleJob("${BASE_NAME}_${EXAMPLE_BRANCH}_GEN") {
    description("The memory-map-exampl demo job that shows the plugin in action on the branch ${EXAMPLE_BRANCH}")
    label 'linux && docker-tools'
    logRotator(-1, 500, -1, -1)
  scm {
        git {
            remote {
                url("${REPO}")
            }
            branch('${EXAMPLE_BRANCH}')
        }

    }
  steps {
        shell('''
export BN=${EXAMPLE_BRANCH}
echo "CURRENT_COMMIT:  ${CURRENT_COMMIT}"
git checkout `git log --format=format:%H --reverse first_$BN^1..last_$BN | sed -n ${CURRENT_COMMIT}p`
./run.sh
git log -n1
#HACK
sed -i '/rom : ORIGIN = 0x60000000, LENGTH = 16M    \\/\\* Change to LENGTH = 32M for larger flash. \\*\\//c\\     rom : ORIGIN = 0x60000000, LENGTH = 16M' viperlite.ld
''')
  }
  
  configure { project ->
    project / publishers << 'net.praqma.jenkins.memorymap.MemoryMapRecorder' {
      wordSize '8'
      showBytesOnGraph false
      scale 'default'
      
      chosenParsers {
        'net.praqma.jenkins.memorymap.parser.gcc.GccMemoryMapParser' {
          'graphConfiguration' {
            'net.praqma.jenkins.memorymap.graph.MemoryMapGraphConfiguration' {
              graphCaption 'Memory sections' 
              graphDataList '.data,.bss,.text'
                }
            'net.praqma.jenkins.memorymap.graph.MemoryMapGraphConfiguration' {
              graphCaption 'Target memory' 
              graphDataList 'rom,ram'
                }
          }
          parserUniqueName 'Gcc'
            mapFile 'blink.map'
            configurationFile 'viperlite.ld'
            parserTitle 'GCC memory map'
        }
      }
    }
   
}
}

