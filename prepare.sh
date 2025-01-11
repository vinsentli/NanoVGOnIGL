cp -af patch/ igl/

file_list=(NanovgSession.h NanovgSession.cpp)

#create soft link
for file in "${file_list[@]}";do
	dst_file=igl/shell/renderSessions/${file}
	test -f ${dst_file} && rm ${dst_file}
	ln -s $(pwd)/example/${file} ${dst_file}
done
