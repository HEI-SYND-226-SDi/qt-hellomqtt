# HelloMQTT example

MQTT with Qt example.


## Install dependencies

        # sudo apt update
        # sudo apt install git nano vim neovim cmake cmake-curses-gui ninja-build g++ gdb qt5-default qtconnectivity5-dev qtbase5-private-dev
        # git clone --branch v5.11.3 https://github.com/qt/qtmqtt.git
        # cd qtmqtt
        # qmake
        # make -j 4
        # sudo make install
    
    
## Clone repository

        # git clone https://github.com/HEI-SYND-226-SDi/qt-hellomqtt.git


## Build

        # mkdir Release
        # cd Release
        # cmake -G Ninja -DCMAKE_BUILD_TYPE=Release ..
        # ninja
        
        
## Run

        # ./HelloMQTT
