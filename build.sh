#!/bin/bash

# Project name
p_name='pacman'

# Setup and build folders
out="out"
bin="bin"

# Release folder
dist="dist"

# 
meson setup $out

if [ ! -z $1 ]  ;then
  if [[ $1 == "dev" ]];then
    if [ ! -d $bin ]; then
      mkdir $bin
    fi
    meson compile -C $out
    mv $out/$p_name $bin
    ./$bin/$p_name
  fi
  if [[ $1 == "prod" ]];then
    if [! -d $dist ];then
      mkdir $dist
    fi
    meson dist -C $out
    mv $out/$p_name $dist
  fi
fi
