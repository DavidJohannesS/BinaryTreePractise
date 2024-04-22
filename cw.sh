#!/bin/bash
tmux new-session -d -s BinaryTree2.0
tmux rename-window Main
tmux split-window -h 
tmux select-pane -t 0
tmux send-keys "nvim main.cpp" C-m
tmux select-pane -t 1 
tmux send-keys "cat comp.sh" C-m
#---------------------------Main/Compwindow
tmux new-window -n TreeNode
tmux split-window -h
tmux select-pane -t 0
tmux send-keys "nvim Treenode.cpp" C-m
tmux select-pane -t 1
tmux send-keys "nvim TreeNode.h" C-m
#-----------------------------TreeNode.cpp/h 
tmux attach-session -t BinaryTree2.0
