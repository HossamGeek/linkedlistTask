@echo off
echo Starting build...

REM Build
start cmd /k "g++ *.cpp -o app.exe && app.exe"

echo All set! Ready to work.
pause
