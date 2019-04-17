/*
  A jQuery plug-in: this one converts the selected elements into a
  “dial” control.
*/
(($) => {
  $.fn.dial = function (options) {
    const $this = this

    let $current = null
    let anchorX = 0

    $this.addClass("dial").mousedown(function (event) {
      $current = $(this)
      anchorX = event.screenX - ($current.data('dial-angle') || 0)
    })

    $(document).mousemove(event => {
      if ($current) {
        const currentAngle = $current.data('dial-angle') || 0
        const newAngle = Math.min(Math.max(event.screenX - anchorX, -90), 90)
        const newCss = `perspective(500px) rotateZ(${newAngle}deg)`

        $current.css({
          'transform': newCss
        }).data({
          'dial-angle': newAngle
        })

        if ($.isPlainObject(options) && $.isFunction(options.change)) {
          options.change.call($current, currentAngle, newAngle)
        }
      }
    }).mouseup(() => {
      $current = null
    })

    return $this
  }
})(jQuery)
