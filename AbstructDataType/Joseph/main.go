package main 

import (
    "fmt"
)

type Node struct {
    Next *Node
    Val  int
}

func main(){

    arr := []int{1, 2, 3, 4, 5, 6}
    headPoint := create(arr)

    res := Josefh(headPoint, 4)

    fmt.Println(res)
}


func create(arr []int) *Node {
    head := &Node{}
    head.Next = head

    p := head

    for _, v := range arr {
        node := &Node{
            Next: head.Next,
            Val: v,
        }
        p.Next = node
        p = node
    }

    return head
}

func find(headPoint *Node) {
    node := headPoint.Next

    for node != nil {
        fmt.Print(node.Val, "\t")
        node = node.Next
    }
}


func Josefh(headPoint *Node, n int) int {
    p := headPoint.Next

    pre := &Node{}

    count := 1
    for p.Next != p {

        if count < n {

            pre = p
            count++
        } else {
            fmt.Println("被剔除的元素：", p.Val)

            pre.Next = p.Next
            count = 1
        }

        p = p.Next 
    }

    return p.Val
}
