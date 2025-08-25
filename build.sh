#!/bin/bash

# Color codes
RED='\033[0;31m'
GREEN='\033[0;32m'
BLUE='\033[0;34m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

# Icons
CHECK="✅"
CROSS="❌"
ROCKET="🚀"
HAMMER="🔨"
SPARKLES="✨"

# Functions for additional commands
format() {
    echo -e "${BLUE}${SPARKLES} Formatting code...${NC}"
    # Only format files that actually exist
    find src/ -name "*.c" -o -name "*.h" | xargs -r clang-format -i
    echo -e "${GREEN}${CHECK} Formatting complete${NC}"
}

clean() {
    echo -e "${YELLOW}${HAMMER} Cleaning build directory...${NC}"
    rm -rf build/
    echo -e "${GREEN}${CHECK} Clean complete${NC}"
}

# Handle arguments
if [ "$1" = "format" ]; then
    format
    exit 0
elif [ "$1" = "clean" ]; then
    clean
    exit 0
fi

# Default build process
echo -e "${BLUE}${ROCKET} Start the building process...${NC}"

if cmake -B build; then
    echo -e "${GREEN}${CHECK} CMake configuration successful${NC}"
else
    echo -e "${RED}${CROSS} CMake configuration failed${NC}"
    exit 1
fi

if cmake --build build; then
    echo -e "${GREEN}${CHECK} Build successful! Run with: ${YELLOW}./build/bin/shell${NC}"
else
    echo -e "${RED}${CROSS} Build failed${NC}"
    exit 1
fi
