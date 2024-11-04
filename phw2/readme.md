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