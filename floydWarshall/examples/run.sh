#!/bin/bash

floyd=../floydWarshall.bin

(cd ../ && make)

echo "Testando algoritmo de Floyd"
for i in ./*.dat
do
    filename=$(basename "$i")
    echo -e "\e[33mInstância $i salva em outputs/res_$filename\e[0m"

    $floyd -f "$i" -o "res_$filename"
done
