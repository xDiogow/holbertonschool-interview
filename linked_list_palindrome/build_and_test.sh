#!/bin/bash

source "build.sh"

expected_output="1
17
972
50
98
98
50
972
17
1
Linked list is a palindrome"

actual_output=$(./palindrome)

if [ "$actual_output" = "$expected_output" ]; then
    echo "✅ Output matches expected!"
else
    echo "❌ Output differs!"
    echo "Expected:"
    echo "$expected_output"
    echo "Got:"
    echo "$actual_output"
fi
