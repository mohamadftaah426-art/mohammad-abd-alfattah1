#!/bin/bash

report_file="notes/report_$(date +%Y-%m-%d).txt"

echo "اسم المستخدم: $(whoami)" > "$report_file"
echo "المسار الحالي: $(pwd)" >> "$report_file"
echo "عدد الملفات في data/: $(ls -1 data/ | wc -l)" >> "$report_file"
echo "نهاية التنفيذ بنجاح" >> "$report_file"

echo "تم إنشاء التقرير: $report_file"
