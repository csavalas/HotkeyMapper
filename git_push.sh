echo Enter commit message: 
read message
if [ -z "$message" ]
then
	echo "message is empty, using default..."
	message="Updates"
fi
echo git 
echo Adding changes...
git add .
echo Getting status...
git status
echo Committing changes...
git commit -m "$message"
echo Pushing changes...
git push
read -p "Press enter to continue"

