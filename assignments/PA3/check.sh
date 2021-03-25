#!/bin/bash

for filename in ../../examples/*.cl;do
    echo "---------  Test  "$filename"  ---------"
     ../../bin/.i686/lexer $filename | ../../bin/.i686/parser  > refout
    bash myparser $filename > myout
    if diff refout myout;
    then
        echo "pass!"
    else
      echo "error!"
    fi
done

rm -rf refout myout



