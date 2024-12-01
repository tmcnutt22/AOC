package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

func parseLine(line string) int {
	length := len(line)
	var value int = 0

	// char set to check for numbers spelled out
	var byteMap map[byte]bool
	byteMap['z'] = true
	byteMap['o'] = true
	byteMap['t'] = true // two three
	byteMap['f'] = true // four five
	byteMap['s'] = true // six seven
	byteMap['e'] = true
	byteMap['n'] = true

  // map to find string values
  var numStrMap map[string]int
  numStrMap['zero'] = 0
  numStrMap['one'] = 1;
  numStrMap['two'] = 2;
  numStrMap['two'] = 2;


	for i := 0; i < length; i++ {
		if line[i] >= 48 && line[i] <= 57 {
			numInt, err := strconv.Atoi(string(line[i]))
			if err != nil {
				fmt.Println("Could not convert:", err)
			}
			numInt *= 10
			value += numInt
			break
		} else {

		}
	}

	for j := length - 1; j >= 0; j-- {
		if line[j] >= 48 && line[j] <= 57 {
			numInt, err := strconv.Atoi(string(line[j]))
			if err != nil {
				fmt.Println("Could not convert:", err)
			}
			value += numInt
			break
		}
	}

	return value
}

func main() {
	var file *os.File
	var err error

	file, err = os.Open("input.txt")
	if err != nil {
		fmt.Println("Error opening file: ", err)
		return
	}
	defer file.Close()

	var scanner *bufio.Scanner
	scanner = bufio.NewScanner(file)

	var val int = 0
	for scanner.Scan() {
		var line string
		line = scanner.Text()
		val += parseLine(line)
	}

	if err = scanner.Err(); err != nil {
		fmt.Println("Error reading file:", err)
	}

	fmt.Println(val)
	return
}
