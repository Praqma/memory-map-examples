FROM gcc:4.8.5


# Install also cross compiler as the example code need to be cross compiled for ARM
# (keep most in one line to keep resulting docker image smaller - also cleaning temp things up)

RUN wget https://launchpad.net/gcc-arm-embedded/4.8/4.8-2014-q3-update/+download/gcc-arm-none-eabi-4_8-2014q3-20140805-linux.tar.bz2 \
	&& tar -vjxf gcc-arm-none-eabi-4_8-2014q3-20140805-linux.tar.bz2 -C /opt \
	&& rm -r gcc-arm-none-eabi-4_8-2014q3-20140805-linux.tar.bz2 \ 
	&& dpkg --add-architecture i386 && apt-get -y update && apt-get -y install ia32-libs

ENV PATH $PATH:/opt/gcc-arm-none-eabi-4_8-2014q3/bin"

WORKDIR /data
