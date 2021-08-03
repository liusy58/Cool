#!/bin/bash

for filename in ../../examples/*.cl;do
  echo "---------- Test "$filename"  ----------"
  ./lexer $filename > myout
  ./stdlexer $filename > standardout
  if diff myout standardout;
  then
    echo " Passed!!"
    fi
  done

  rm -rf myout standardout