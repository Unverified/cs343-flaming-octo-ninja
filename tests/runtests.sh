TESTS=`cat tests.txt`

for t in `echo $TESTS | tr '\n' ' '`
do
  echo "-------- Running \"$t\" Test --------"
  echo ""

  echo "Description:"
  cat tests/$t.dec
  echo ""

  if [ -f tests/$t ]
    then
    echo "Test File Contents:"
    cat tests/$t
    echo ""
  fi

  echo "Test Execution:"
  bash tests/$t.sh
  echo ""

  echo "Explanation:"
  cat tests/$t.exp
  echo ""
done
