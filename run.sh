if [ $# -eq 0 ];then
	echo "Please provide filename to be built as argument."
	exit 1
fi

cflag="false"
bflag="false"
rflag="false"

while getopts ":c:b:r" opt;do
	case $opt in
		c)
			cflag="true"
			;;
		b)
			cflag="true"
			bflag="true"
			;;
		r)
			cflag="true"
			bflag="true"
			rflag="true"
			;;
		\?)
			echo "Invalid option: -$OPTARG " >&2
			exit 1
			;;
		:)
			echo "Option -$OPTARG requires an argument." >&2
			exit 1
			;;
	esac
done

shift 
filename="${1%.*}"
ext="${1##*.}"
compiler="g++"

if [ $ext = "c" ];then
	compiler="gcc"
elif [ $ext = "cpp" ];then
	compiler="g++"
fi

if [ $cflag = "true" ];then
	"$compiler" -c -g "$1"
	if [ $? -eq 1 ];then
		echo "Compilation failed."
		exit 1
	else
		echo "Compilation was successful. $filename.o is generated."
	fi
fi

if [ $bflag = "true" ];then
	"$compiler" -o "$filename" "$filename.o"
	if [ $? -eq 1 ];then
		echo "Building failed."
		exit 1
	else
		rm "$filename.o"
		echo "Building was successful. Executable $filename will be run."
	fi
fi

if [ $rflag = "true" ];then
	if [ $# -eq 2 ];then
		./"$filename" < $2
	else
		./"$filename"
	fi
fi
