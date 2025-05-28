#!/bin/bash

source "build.sh"

expected_output="1024
402
98
4
3
2
1
0
Linked list has no cycle
Linked list has a cycle"

actual_output=$(./cycle)

if [ "$actual_output" = "$expected_output" ]; then
    echo "✅ Output matches expected!"
else
    echo "❌ Output differs!"
    echo "Expected:"
    echo "$expected_output"
    echo "Got:"
    echo "$actual_output"
fi

