@echo off

echo ���ļ�����������Ҫ��CMSIS��������Ĭ��ɾ��һЩ�ļ���������ѯ���Ƿ�ɾ�������ļ�������㲻֪��ɾ����Щ�ļ��ĺ������һ��ѡN��

rmdir /s /q "Core_A" "CoreValidation" "DAP" "Documentation" "Doxygen" "Driver" "Pack" "RTOS" "RTOS2" "Utilities"

rmdir /s /q "Core_M\Template" "DSP\DSP_Lib_TestSuite" "DSP\Examples" "DSP\Projects"  "NN\Examples" "NN\NN_Lib_Tests" "NN\Scripts" 

echo ɾ��DSP_Lib��NN_Lib��Դ�ļ���
rmdir /s "NN\Source" "DSP\Source"
echo ɾ������Ҫ�ľ�̬����Խ�Լ����ʱ�䡣��Ҫ�����ĸ��������ľ�̬�⣿
echo ɾ��ARM�ľ�̬�⣿
rmdir /s "Lib\ARM"
echo ɾ��GCC�ľ�̬�⣿
rmdir /s "Lib\GCC"
echo ɾ��IAR�ľ�̬�⣿
rmdir /s "Lib\IAR"

echo �������
pause