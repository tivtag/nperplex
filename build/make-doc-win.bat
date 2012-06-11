@echo Generating natural doc from source code..
setlocal 

cd ..\tools\generic\NaturalDocs
mkdir ..\..\..\doc\natural
mkdir ..\..\..\project\doc\natural

NaturalDocs.bat -i "../../../include"  -i "../../../src" -o HTML "../../../doc/natural" -p "../../../project/doc/natural" 
