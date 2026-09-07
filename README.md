# fileorgd
>Simple daemon that quickly organizes a directory's files.


## Requirements
You need to have : `g++` and `make`.

### Arch Linux
```sh
sudo pacman -S g++ make
```

### Ubuntu | Termux | Others
```sh
apt install g++ make
```


## Installation
```sh
git clone https://github.com/HassanIQ777/fileorgd.git && cd fileorgd && make
```
You can also run `make install`


## Usage
```sh
$ fileorgd -h
Usage:
  fileorgd <dir to organize>
  fileorgd -h    print this help message
  fileorgd -v    print version
  fileorgd -s    stop program
```
`fileorgd -h`  prints the help message.

`fileorgd -v`  prints the version like: _fileorgd version v26.9.6-3_.

`fileorgd -s`  runs `pkill fileorgd`.

`fileorgd <DIR>` will start organizing the given directory.

## What it does
 1) The program will create 7 directories: _Others, Pictures, Vidoes, Music, Documents, Code, and APK_.

 2) Then it'll move the  files in the given directory to the correct directories.

 3) Then out of the 7 directories, it'll removed the unused ones.

##### This process happens once every 10 seconds.
---
### Note: The program runs in the background in an infinite loop without the need of a terminal.
---

## Contributing

Contributions are welcome! Please feel free to submit a pull request or open an issue.

## License
This project is licensed under the MIT License See
[`LICENSE`](LICENSE) for details.