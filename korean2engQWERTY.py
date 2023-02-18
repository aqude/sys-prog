import pyperclip
import subprocess

with open("input.txt", "r", encoding="utf-8") as input_file:
  korean_text = input_file.read()

pyperclip.copy(korean_text)

subprocess.call('powershell.exe -Command "Add-Type -AssemblyName PresentationCore; [System.Windows.Clipboard]::SetText([System.Windows.Input.InputLanguage]::CurrentInputLanguage.GetEquivalentKeyboardLayout("qwerty").ToString()); $txt = [System.Windows.Clipboard]::GetText(); [System.Windows.Clipboard]::SetText($txt)"')

qwerty_text = pyperclip.paste()

with open("output.txt", "w", encoding="utf-8") as output_file:
  output_file.write(qwerty_text)
