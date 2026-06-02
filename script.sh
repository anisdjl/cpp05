#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: $0 <ClassName>"
    exit 1
fi

NAME=$1
UPPER_NAME=$(echo "$NAME" | tr '[:lower:]' '[:upper:]')

# 1. Génération du Header (.hpp)
cat << EOF > "${NAME}.hpp"
#ifndef ${UPPER_NAME}_HPP
#define ${UPPER_NAME}_HPP

#include <iostream>

class ${NAME} {
    private:

    public:
        ${NAME}();
        ${NAME}(const ${NAME} &src);
        ~${NAME}();
        ${NAME} &operator=(const ${NAME} &src);
};

#endif
EOF

# 2. Génération du Source (.cpp)
cat << EOF > "${NAME}.cpp"
#include "${NAME}.hpp"

${NAME}::${NAME}() {
    std::cout << "${NAME} default constructor called" << std::endl;
}

${NAME}::${NAME}(const ${NAME} &src) {
    std::cout << "${NAME} copy constructor called" << std::endl;
    *this = src;
}

${NAME}::~${NAME}() {
    std::cout << "${NAME} destructor called" << std::endl;
}

${NAME} &${NAME}::operator=(const ${NAME} &src) {
    std::cout << "${NAME} assignment operator called" << std::endl;
    if (this != &src) {
       
    }
    return *this;
}
EOF

echo "Classe ${NAME} générée avec succès (${NAME}.hpp / ${NAME}.cpp)"