# Data Structure Homework 3

## Overview

Student ID: 41247001S
姓名：盧昱安

Developed in linux env, suggest using this application in linux/unix env.
There's a makefile so just "make" and open the ./result

## Functions

完成所有要求的功能

Data Structure:
以 stack 實作 infix expression operator 紀錄，來建樹
以 stack 紀錄最後數字帶入變數的 Postorder Evaluation
以 queue 紀錄 level-order 中每個樹節點
以 binary tree 紀錄二元運算樹


## 檔案架構

main.c : 主程式，完全模組化的寫法架構
binary_tree.h : 將 stack、queue、binary_tree 的 struct 宣告
    大量 function (下面會有重要的function的說明)

## 實際測試紀錄

初始字串 : (a+b)*c+d
a = 5
b = 5
c = 2
d = 3 輸出 23

初始字串 : a+b+c+d
a = 1
b = 2
c = 3
d = 4 輸出 10

## 程式完整架構及主要 function 和 #define 意思

架構上以 main 作為 IO 讀取
將讀取到的初始字串傳到 binary_tree.h 中的 buildTree() function
這個 function 會將讀取到的初始字串轉變為一顆二元樹

實作了四個（雖然題目只要求三個）不一樣的樹遍例方式
level-order, postorder, inorder, preorder
分別為四個不同的 function 輸出 print_[order]

stack, queue 相關 :
push() , push_queue()
pop() , pop_queue()
push_num() , pop_num() 有一個數字為 val 的 stack
原本 pop() , push() 則為給 val 為 char 的 stack

## 重要function

treeToPostOrderStack() : 將二元樹轉變為一個 PostOrder 的 stack
postfixToTree() : 將前面 infix expression 轉變為 postfix 後轉為二元樹的 function
operators_priority() : 檢查運算子的優先程度(處理infix expression 時使用)
buildTree() : 核心，將輸入的字串轉變為一顆 binary tree




