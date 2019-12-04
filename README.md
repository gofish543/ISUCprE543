# ISUCprE543

### Application Requirements
Please make sure the following software is installed on your machine before attempting to compile the code
* cmake
* git
* gpp
* libncurses-dev
* ncurses
* libnm-dev
* pcap-dev

```bash
sudo apt-get install cmake git gpp libncurses-dev ncurses libnm-dev libpcap-dev
```

### Compilation
```bash
# Clone the repository
git clone https://github.com/gofish543/ISUCprE543.git
cd ISUCprE543

# Generate build folder
mkdir build
cd build

# Build the application
cmake ../
make
```

### Execution
```bash
# Format: ./ISUCprE543 <interface>
./ISUCprE543 wlo1
```