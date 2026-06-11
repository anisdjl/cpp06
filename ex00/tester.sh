#!/bin/bash

# Couleurs pour l'affichage
GREEN='\033[0;32m'
RED='\033[0;31m'
YELLOW='\033[0;33m'
RESET='\033[0;m'

if [ ! -f "./convert" ]; then
    echo -e "${RED}Erreur : l'exécutable './convert' est introuvable. Compile avant !${RESET}"
    exit 1
fi

run_test() {
    local input="$1"
    echo -e "${YELLOW}-----------------------------------------${RESET}"
    echo -e "Test avec l'input : ${GREEN}\"${input}\"${RESET}"
    echo -e "${YELLOW}-----------------------------------------${RESET}"
    ./convert "$input"
    echo ""
}

echo -e "${GREEN}=== DÉBUT DU TESTEUR AUTOMATIQUE EX00 ===${RESET}\n"

# 1. CAS FACILES
run_test "c"
run_test "42"
run_test "0"
run_test "-42"

# 2. FLOATS ET DOUBLES STANDARDS
run_test "42.42f"
run_test "42.42"
run_test "0.0f"
run_test "0.0"
run_test ".42f"

# 3. LITTÉRAUX SPÉCIAUX (Le gros piège)
run_test "nan"
run_test "nanf"
run_test "inf"
run_test "inff"
run_test "-inf"
run_test "-inff"
run_test "+inf"
run_test "+inff"

# 4. OVERFLOWS DETECTABLES
run_test "2147483647"       # INT_MAX
run_test "2147483648"       # INT_MAX + 1 (Doit mettre int: impossible)
run_test "-2147483648"      # INT_MIN
run_test "-2147483649"      # INT_MIN - 1 (Doit mettre int: impossible)
run_test "3.402823e+38"     # FLOAT_MAX

# 5. ERREURS SYNTAXIQUES (La douane doit tout bloquer)
run_test "42.42ff"          # Double f
run_test "42.42f42"         # Lettres après le f
run_test "42a"              # Lettre au milieu
run_test "abc"              # Chaîne de caractères longue
run_test "42.42.42"         # Multiples points
run_test "+--42"            # Multiples signes
run_test ""                 # Chaîne vide

echo -e "${GREEN}=== FIN DES TESTS ===${RESET}"