#!/usr/bin/env bash
{
    cat <<-'EOF'
# This file lists all individuals who have contributed content to the
# repository.
# For how it is generated, see `generate-authors.sh`.
EOF
echo
git log --format='%aN <%aE>' | LC_ALL=C.UTF-8 sort -uf |
    grep -v "github.com"
}>AUTHORS
