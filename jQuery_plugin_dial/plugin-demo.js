$(() => {
  let $log = $(".event-log")
  let $dot = $(".dot")
  let logEvent = (message) => {
    $log.text($log.text() + message + "\n")
      .scrollTop($log[0].scrollHeight - $log.height())
  }
  let showHide = (newAngle) => {
    if (newAngle > 10) {
      $dot.css('display', 'none')
    } else {
      $dot.css('display', 'inline-block')
    }
  }

  $(".dial-this").dial({
    change: function (oldAngle, newAngle) {
      logEvent("dial: dialed from " + oldAngle + " to " + newAngle)
      showHide(newAngle)
    }
  })

  $(".dot").dial({
    change: function (oldAngle, newAngle) {
      logEvent("dial: dialed from " + oldAngle + " to " + newAngle)
    }
  })

  $(".img-responsive").dial({
    change: function (oldAngle, newAngle) {
      logEvent("dial: dialed from " + oldAngle + " to " + newAngle)
    }
  })
})
