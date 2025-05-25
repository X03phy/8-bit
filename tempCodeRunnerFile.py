from PIL import Image, ImageEnhance

# Ouvre l'image
im = Image.open('../ac.png')

# Crée un enhancer de luminosité
enhancer = ImageEnhance.Brightness(im)

# Facteur >1 augmente la luminosité, <1 la diminue
facteur = 3.0  # par exemple, 50% plus lumineux

# Applique l'amélioration
im_lumineuse = enhancer.enhance(facteur)

# Sauvegarde le résultat
im_lumineuse.save('mon_image_lumineuse.png')