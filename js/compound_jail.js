/**
 * @file
 * Add JAIL for fancy loading of images.
 */

Drupal.settings.islandora_compound_object_JAIL_jQuery = jQuery.noConflict(true);
(function ($) {
    Drupal.behaviors.islandora_compound_object_JAIL = {
        attach: function(context, settings) {
            $('img.islandora-compound-object-jail').jail({
                triggerElement:'#block-islandora-compound-object-compound-jail-display',
                event: 'scroll'
            });
        }
    };
})(Drupal.settings.islandora_compound_object_JAIL_jQuery);
