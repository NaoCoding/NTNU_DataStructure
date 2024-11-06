# Data Structure Homework 2

## Overview

Student ID: 41247001S
姓名：盧昱安

Developed in linux env, suggest using this application in linux/unix env.
There's a makefile so just "make" and open the ./result

## Functions

完成所有要求的功能
以 double-link-list 作為當前 string 狀態的存儲
以 stack 紀錄 command history 和 undo history
實作中將 cursor 也視為一個 link-list 的 node，使其橫移以 link-list 實作練習


## 檔案架構

main.c : 主程式，完全模組化的寫法架構
IO.h : 解析輸入字串及輸入偵測
    -- INPUT 
UI.h : 大量 #define 存儲模組化的錯誤訊息及界面輸入
LINKLIST.h : link-list library
    -- parse command
    -- parse strings to link list
    -- parse and handle COMMAND
STACK.h : stack library
    -- handle pop , push, and stack typedef
DEBUG.h : for debugging

## 實際測試紀錄

初始字串：hello world
backspace 直到刪除整個字串後 undo 到底並 redo 回來

insert 字串
delete 後 undo 再 redo

移動 cursor 後 undo 
移動 cursor 後 delete, insert, backspace

## 程式完整架構及主要 function 和 #define 意思

架構上以 UI 顯示 -> 讀取指令/字串 -> COMMAND() function 處理指令 ->
對指令做出反應 -> 儲存指令紀錄/儲存 undo 紀錄

以 stack 儲存 undo 和 command 紀錄
若為刪除字元，會同時儲存刪除的指令和被刪除的字元

function 和 #define 的內容如下：

處理指令相關
COMMAND() : 核心，parse 指令後呼叫或產生不同的功能
Arr2LinkList() : 字串轉為 link-list

Link list 相關 :
getCursor() : 查找 cursor 的位置 (= linklist search node)
append() : 連結兩個 link-list (= link-list append)
其他 link list 操作如左右兩節點互換、刪除、insert、pop 位於 COMMAND() 中實做

Stack 相關 : 
stack_push() , stack_pop()

IO 相關
readline() : 讀取 initial string
readlineCommand() : 讀取指令
DISPLAY_CURRENT() : 顯示目前的 link-list

UI 相關
CLEAR : 清除 terminal 畫面
FOOTER : 學號與標題
START_MESSAGE : Please enter initial string
COMMAND_MESSAGE : 指令列表

ERROR 相關
START_ERROR_MESSAGE : 初始字串錯誤
COMMAND_ERROR_MESSAGE : 指令錯誤
UNDO_EMPTY : undo stack 為空錯誤
COMMAND_EMPTY : 指令紀錄為空錯誤





