

$command1 = "g++ .\exo5.cpp -o .\exo5.exe"
$command2 = ".\exo5.exe"

Invoke-Expression $command1
if ($LASTEXITCODE -eq 0) {
    Invoke-Expression $command2
}