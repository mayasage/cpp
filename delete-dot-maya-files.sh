#!/bin/sh

ext="*.maya"

fileCount=$(find . -type f -name "${ext}" | wc -l)

if [ $fileCount -gt 0 ]; then

  # Print Found Files
  echo "Files Found:"
  find . -type f -name "*.maya" -exec echo {} \;

  echo "Deleting..."

  # Delete Found Files
  find . -type f -name "*.maya" -exec rm {} \;
  echo "Deleted found Files."

else

  echo "No files found."

fi
