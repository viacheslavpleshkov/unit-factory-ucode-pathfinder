<p align="center">
    <a href="https://unit.ua/en/" target="_blank">
        <img src="https://github.com/slava-pleshkov/unit-factory-ucode/blob/master/.git_images/unit_logo.png?raw=true" height="100px">
    </a>
    <a href="https://apply.ucode.world/" target="_blank">
        <img src="https://github.com/slava-pleshkov/unit-factory-ucode/blob/master/.git_images/ucode_logo.png?raw=true" height="100px">
    </a>
    <h1 align="center">unit-factory-ucode-pathfinder</h1>
    <br>
</p>
<p align="center">🔭 Learn pathfinding algorithms</p>

## Used technologies

C, Makefile, Algorithm, File system, Memory, Terminal, Bash, Unix, CBL framework

<hr>

## How to use
1. Compilation this command `make`
1. Reinstalliation this command `make reinstall`
1. Uninstalliation this command `make uninstall`

## Usage example

```
./pathfinder tests_file/file_name
```
## Examples

## File

```
4
Greenland-Bananal,8
Fraser-Greenland,10
Bananal-Fraser,3
Java-Fraser,5
```

## Output

```
========================================
Path: Greenland -> Bananal
Route: Greenland -> Bananal
Distance: 8
========================================
========================================
Path: Greenland -> Fraser
Route: Greenland -> Fraser
Distance: 10
========================================
========================================
Path: Greenland -> Java
Route: Greenland -> Fraser -> Java
Distance: 10 + 5 = 15
========================================
========================================
Path: Bananal -> Fraser
Route: Bananal -> Fraser
Distance: 3
========================================
========================================
Path: Bananal -> Java
Route: Bananal -> Fraser -> Java
Distance: 3 + 5 = 8
========================================
========================================
Path: Fraser -> Java
Route: Fraser -> Java
Distance: 5
========================================
```

## Possible errors

1. Invalid number of command-line arguments.
2. The file does not exist.
3. The file is empty.
4. The first line contains something other than digits.
5. One of the remaining lines doesn't match the pattern ```str1-str2,n```.
6. The number received on the first line does not coincide with the number of islands.

## License

Collision is an open-sourced software licensed under the [MIT license](LICENSE.md).