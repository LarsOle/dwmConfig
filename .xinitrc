feh --bg-fill /home/lars/.wallpaper.png
conky | while true; read line; do xsetroot -name "$line"; done&
exec dwm
