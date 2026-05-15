#!/bin/bash

welcome(){
    echo "Welcome, $1"
}

if [ $# -lt 1 ]; then
    echo "Usage: $0 <name>"
    exit 1
fi

echo "Script name: $0"
echo "First arg: $1"
echo "Args count: $#"

welcome "$1"
