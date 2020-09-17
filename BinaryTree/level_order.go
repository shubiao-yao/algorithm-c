package main 

import (
    "fmt"
)

func main() {

	tRoot := create()

	scan(tRoot)
}

type TreeNode struct{
	Val int
	Right *TreeNode 
	Left *TreeNode
}

func create() *TreeNode {
	var que [100]*TreeNode
	arr := []int{100, 1, 2, 3, 4, 5, 6, 7, 0} 

	t := &TreeNode{}
	t.Val = arr[1]
	que[1] = t

	for i := 2; i <= len(arr); i++ {
		if arr[i] == 0 {
			break
		}
		
		q := &TreeNode{}
		q.Val = arr[i]
		que[i] = q

		if i % 2 == 0 {
			que[i/2].Left = q  
		} else {
			que[i/2].Right = q
		}
	}
	return t
}

type Btree struct {
	Queue [100]*TreeNode
	Front int
	Rear  int
}

func scan(t *TreeNode) {
	var bt Btree
	if t != nil {
		bt.Rear++
		bt.Queue[bt.Rear] = t
	}

	for bt.Rear != bt.Front {
		bt.Front++

		t = bt.Queue[bt.Front]
		fmt.Print(t.Val, "\t")

		if t.Right != nil {
			bt.Rear++
			bt.Queue[bt.Rear] = t.Right
		}

		if t.Left != nil {
			bt.Rear++
			bt.Queue[bt.Rear] = t.Left
		}
	}
}
