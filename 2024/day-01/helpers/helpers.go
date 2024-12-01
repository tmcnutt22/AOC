package helpers

import (
	"bufio"
	"math"
	"os"
	"sort"
	"strconv"
	"strings"
)

func Day01() int {
	// create 2 lists
	var list1 []int
	var list2 []int

	file, err := os.Open("helpers/input.txt")
	if err != nil {
		panic(err)
	}

	defer file.Close()

	// create a scanner
	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		s := scanner.Text()
		var strs []string = strings.Split(s, "   ")
		if len(strs) != 2 {
			break
		}

		i, err := strconv.Atoi(strs[0])
		if err != nil {
			panic(err)
		}
		j, err := strconv.Atoi(strs[1])
		if err != nil {
			panic(err)
		}

		list1 = append(list1, i)
		list2 = append(list2, j)
	}
	sort.Ints(list1)
	sort.Ints(list2)

	diff := 0
	for index, value := range list1 {
		diff += int(math.Abs(float64(value - list2[index])))
	}

	return diff
}

func Day02() int {
	file, err := os.Open("helpers/input.txt")
	if err != nil {
		panic(err)
	}

	scanner := bufio.NewScanner(file)

	var list1 []int
	var list2 []int

	for scanner.Scan() {
		s := scanner.Text()
		var strs []string = strings.Split(s, "   ")
		if len(strs) != 2 {
			break
		}

		i, err := strconv.Atoi(strs[0])
		if err != nil {
			panic(err)
		}
		j, err := strconv.Atoi(strs[1])
		if err != nil {
			panic(err)
		}

		list1 = append(list1, i)
		list2 = append(list2, j)
	}

	intFreq := make(map[int]int)
	for _, value := range list2 {
		if _, exists := intFreq[value]; !exists {
			intFreq[value] = 0
		}

		intFreq[value] = intFreq[value] + 1
	}

	res := 0
	for _, value := range list1 {
		if _, exists := intFreq[value]; exists {
			res += value * intFreq[value]
		}
	}

	return res
}
