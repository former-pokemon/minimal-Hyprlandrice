# Hyprland Rice 🚀✨🎨

Welcome to my Hyprland rice setup! I use Arch, btw. This is a custom Linux desktop environment built for speed, simplicity, and a polished aesthetic. If you love tinkering with your setup and want your desktop to look and feel just right, you’re in the right place. 🌿


## Repository 📂🔗

[**GitHub Repository**](https://github.com/former-pokemon/Hyprland-rice)

## Features 🖥️⚡🎯

- **Window Manager:** Hyprland — dynamic tiling, lightweight, and ridiculously customizable
- **Status Bar:** Waybar — flexible and easy to style with CSS
- **Terminal Emulator:** Kitty — GPU-accelerated and fast as hell
- **Application Launcher:** Rofi — minimal, fast, and super scriptable
- **Notification Daemon:** Swaync — simple, lightweight, and just works
- **File Manager:** Thunar — reliable and easy to use
- **Compositor & Effects:** Hyprland's built-in effects (blur, shadows, animations)
- **Wallpaper Manager:** Swww — lightweight and smooth wallpaper handling

## Installation 🛠️📥🖱️

1. Clone the repository:

```bash
git clone https://github.com/former-pokemon/Hyprland-rice
cd Hyprland-rice
```

2. Copy the configuration files to your `.config` directory:

```bash
cp -r .config/* ~/.config/
```

3. Reload Hyprland or log out and log back in to see the changes. 🔄

## Theming & Styling 🎨🖌️✨

I went for a modern, minimal with vibrant accents. The CSS files for Waybar and GTK themes are fully customizable, so tweak them to your heart’s content.
suryansh is a bich
Example Waybar styling:

```css
/* Waybar styles */
#waybar {
    background: rgba(0, 0, 0, 0.8);
    border-radius: 10px;
    padding: 6px;
    color: #cdd6f4;
    font-family: 'JetBrains Mono', monospace;
}

#clock {
    font-weight: bold;
    color: #89b4fa;
    font-size: 14px;
}
```

It’s your rice, so make it yours, after all. 🧑‍🎨

## Showcase 🎥

![Hyprland Showcase](./preview.gif)
![Hyprland Showcase](./lockscreen.gif)
 
With audio: 
[![Watch the showcase](https://img.youtube.com/vi/lkBbZEdpgg8/0.jpg)](https://youtu.be/lkBbZEdpgg8)

Or click the link: [https://youtu.be/lkBbZEdpgg8](https://youtu.be/lkBbZEdpgg8)

```ini
###################
### KEYBINDINGS ###
###################

# See https://wiki.hyprland.org/Configuring/Keywords/
$mainMod = SUPER # Sets "Windows" key as main modifier

# Example binds, see https://wiki.hyprland.org/Configuring/Binds/ for more
bind = $mainMod, return, exec, $terminal
bind = $mainMod, Q, killactive,
bind = $mainMod, M, exit,
bind = $mainMod, E, exec, $fileManager
bind = $mainMod, V, togglefloating,
bind = $mainMod, Z, exec, $menu
bind = $mainMod, P, pseudo, # dwindle
bind = $mainMod, J, togglesplit, # dwindle
bind = $mainMod, I, exec, pkill waybar
bind = $mainMod, U, exec, waybar
bind = SUPER, K, exec, ~/.wallpaperwatcher.sh
bind = SUPER, O, exec, hyprlock
bind = SUPER, F, fullscreen
bind = SUPER, A, pin

# Switch workspaces with mainMod + [0-9]
bind = $mainMod, 1, workspace, 1
bind = $mainMod, 2, workspace, 2
bind = $mainMod, 3, workspace, 3
bind = $mainMod, 4, workspace, 4
bind = $mainMod, 5, workspace, 5
bind = $mainMod, 6, workspace, 6
bind = $mainMod, 7, workspace, 7
bind = $mainMod, 8, workspace, 8
bind = $mainMod, 9, workspace, 9
bind = $mainMod, 0, workspace, 10

# Move active window to a workspace with mainMod + SHIFT + [0-9]
bind = $mainMod SHIFT, 1, movetoworkspace, 1
bind = $mainMod SHIFT, 2, movetoworkspace, 2
bind = $mainMod SHIFT, 3, movetoworkspace, 3
bind = $mainMod SHIFT, 4, movetoworkspace, 4
bind = $mainMod SHIFT, 5, movetoworkspace, 5
bind = $mainMod SHIFT, 6, movetoworkspace, 6
bind = $mainMod SHIFT, 7, movetoworkspace, 7
bind = $mainMod SHIFT, 8, movetoworkspace, 8
bind = $mainMod SHIFT, 9, movetoworkspace, 9
bind = $mainMod SHIFT, 0, movetoworkspace, 10

# Example special workspace (scratchpad)
bind = $mainMod, S, togglespecialworkspace, magic
bind = $mainMod SHIFT, S, movetoworkspace, special:magic

# Scroll through existing workspaces with mainMod + scroll
bind = $mainMod, mouse_down, workspace, e+1
bind = $mainMod, mouse_up, workspace, e-1

# Move/resize windows with mainMod + LMB/RMB and dragging
bindm = $mainMod, mouse:272, movewindow
bindm = $mainMod, mouse:273, resizewindow

# Laptop multimedia keys for volume and LCD brightness
bindel = ,F3, exec, wpctl set-volume @DEFAULT_AUDIO_SINK@ 5%+ 
bindel = ,F2, exec, wpctl set-volume @DEFAULT_AUDIO_SINK@ 5%- 
bindel = ,F1, exec, wpctl set-mute @DEFAULT_AUDIO_SINK@ toggle
bindel = ,XF86AudioMicMute, exec, wpctl set-mute @DEFAULT_AUDIO_SOURCE@ toggle
bindel = ,F7, exec, brightnessctl s 10%+
bindel = ,F6, exec, brightnessctl s 10%-

# Requires playerctl
bindl = , XF86AudioNext, exec, playerctl next
bindl = , XF86AudioPause, exec, playerctl play-pause
bindl = , XF86AudioPlay, exec, playerctl play-pause
bindl = , XF86AudioPrev, exec, playerctl previous
```
## Wallpapers
all wallpapers are in ~/Pictures 
swww keybindings will not work if you dont put these images in you ~/Pictures folder
or you can change the keybinds as you wish too __line 322 in ~/.config/hypr/hyprland.conf__




## Future Enhancements 🚧🔧📘

- I have added //window+arrow keys to resixze windows
- Wallpaper rotation scripts
- System monitoring widgets for Waybar

## Contributing & Support 🫂💡📩

Got ideas or found a bug? Open an issue or fork the repo!

- **GitHub Issues:** For bug reports and feature requests
- **Email:** yathubhai5612@gmail.com

Happy ricing! 🎉🌈🔑

---


_Made with love, late nights, and way too many terminal windows. 🚀💻🧠_

