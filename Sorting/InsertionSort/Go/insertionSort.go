package main

import (
	"fmt"
)

func main() {
	toSort := []int{1, 35, 4, 7, 1, 4, 8, 2, 36, 454, 0, 14235, -1, 333}
	sort(toSort)
	fmt.Printf("%v", toSort)
}

func sort(toSort []int) {
	for j := 1; j < len(toSort); j++ {
		key := toSort[j]
		i := j - 1
		for i >= 0 && toSort[i] > key {
			toSort[i+1] = toSort[i]
			i--
		}
		toSort[i+1] = key
	}
}
