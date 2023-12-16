package main

import "fmt"

func swap(a, b *int) {
	var c = *a
	*a = *b
	*b = c
}

func removeElements(nums []int, val int) int {
	var valCount int = 0
	var i, j = 0, 0

	var arrLen = len(nums)
	j = arrLen - 1

	for i < j {
		if nums[i] == val {
			for nums[j] == val {
				j--
			}
			swap(&nums[i], &nums[j])
		} else {
			valCount++
		}
		i++
	}

	return valCount
}

// убрать повторы из массива( без использования другого массива )?

func main() {
	var k int = 0

	var numbers2 []int = []int{3, 2, 2, 3}
	k = removeElements(numbers2, 3)
	fmt.Println(k)

	fmt.Printf("numbers2: %v\n", numbers2)

	var numbers []int = []int{0, 1, 2, 2, 3, 0, 4, 2}
	k = removeElements(numbers, 2)

	fmt.Println(k)
	fmt.Printf("numbers: %v\n", numbers)
}
